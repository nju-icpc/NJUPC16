DEPS = $(shell find src) 

njupc-div1.pdf : main.tex $(DEPS)
	xelatex '\def\div1{}\input{main.tex}'
	xelatex '\def\div1{}\input{main.tex}'
	mv main.pdf $@

njupc-div2.pdf : main.tex $(DEPS)
	xelatex '\def\div2{}\input{main.tex}'
	xelatex '\def\div2{}\input{main.tex}'
	mv main.pdf $@

.PHONY : ALL

.DEFAULT_GOAL = ALL

ALL : njupc-div1.pdf njupc-div2.pdf

clean:
	rm -rf njupc-div1.pdf njupc-div2.pdf main.aux main.log
