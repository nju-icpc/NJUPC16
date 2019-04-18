DEPS = $(shell find src -type f)

njupc-div1.pdf : main.tex $(DEPS)
	xelatex '\def\divone{}\input{main.tex}'
	xelatex '\def\divone{}\input{main.tex}'
	mv main.pdf $@

njupc-div2.pdf : main.tex $(DEPS)
	xelatex '\def\divtwo{}\input{main.tex}'
	xelatex '\def\divtwo{}\input{main.tex}'
	mv main.pdf $@

.PHONY : ALL div1 div2 clean

.DEFAULT_GOAL = ALL

ALL : njupc-div1.pdf njupc-div2.pdf

div1 : njupc-div1.pdf
	xdg-open $<

div2 : njupc-div2.pdf
	xdg-open $<

clean:
	rm -rf njupc-div1.pdf njupc-div2.pdf main.aux main.log
