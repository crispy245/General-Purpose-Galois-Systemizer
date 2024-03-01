#
# Copyright (C) 2018
# Function: generate the module for finite field elements multiplication.
# Authors: Wen Wang <wen.wang.ww349@yale.edu>
#          Ruben Niederhagen <ruben@polycephaly.org>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

import argparse

parser = argparse.ArgumentParser(description='Generate GF(m) multiplier module.',
                formatter_class=argparse.ArgumentDefaultsHelpFormatter)
parser.add_argument('-m','--gf', dest='gf', type=int, default=13,
          help='field 2^m')
args = parser.parse_args()


gf = args.gf

F.<x> = GF(2)[]
K.<a> = GF(2^gf, modulus="first_lexicographic")

def set_red(f, g):
  diff = len(f) - g[0] - 1

  while diff >= 0:
    s = f[-1]

    for i in g:
      f[diff + i] = s.symmetric_difference(f[diff + i])

    while len(f[-1]) == 0:
      del f[-1]

    diff = len(f) - g[0] - 1

  return f

#print(f'Modulus: {K.modulus()}')

f = []

for i in range(gf*2):
  f.append(set([i]))

f_red = set_red(f, K.modulus().exponents()[::-1])



mul = []
for i in range(gf*2):
  mul.append([])

for i in range(gf):
  for j in range(gf):
    mul[i+j].append("dinA[{0}]*dinB[{1}]".format(i,j))


fin = []
for i in range(gf):
  fin.append([])

for i, l in enumerate(f_red):
  for j in l:
    fin[i] += mul[j]


# verify
for i in range(16):
  ge = K.random_element()
  he = K.random_element()

  dinA = ge.polynomial()
  dinB = he.polynomial()
  
  tmp = 0
  
  for i, t in enumerate(fin):
    for j in t:
      tmp += x^i * eval(j)

  assert sage_eval(str(tmp), locals={'x':a}) == (ge*he)


print("""module gf_mul (
  input            clk,
  input  [{0} : 0] dinA,
  input  [{0} : 0] dinB,
  output [{0} : 0] dout
);\n""".format(gf-1))

for i, l in enumerate(fin):
  print("  assign dout[{0}] = ".format(i) + " ^ ".join([t.replace("*", "&") for t in l]) + ";")

print("\nendmodule")

