.PHONY : ALL clean

ALL : div1.tsv div2.tsv

%.tsv : %.json make.py team.csv
	./make.py < $< > $@

clean :
	rm -rf *.tsv
