
all: run 

run: mad inv


.PHONY: mad
mad: new_mad old_mad

.PHONY: new_mad 
new_mad:
	sage gen_mad_general.sage -m 3 > new_mad.txt

.PHONY: old_mad 
old_mad:
	sage gen_mad.sage -m 2 > old_mad.txt

.PHONY: inv
inv: new_inv old_inv

.PHONY: new_inv
new_inv:
	sage gen_inv_general.sage -m 3 > new_inv.txt

.PHONY: old_inv
old_inv:
	sage gen_inv.sage -m 1 > old_inv.txt

.PHONY: new_comb
new_comb:
	python gen_comb_SA.py -n 4 -b 1 -m 3 --name comb_SA > comb_SA.txt

.PHONY: clean 
clean:
	rm -rf *.txt
