DEPS = $(shell find src -type f)

njupc-div1.pdf : main.tex $(DEPS)
	xelatex '\def\divone{}\input{main.tex}'
	xelatex '\def\divone{}\input{main.tex}'
	mv main.pdf $@

njupc-div2.pdf : main.tex $(DEPS)
	xelatex '\def\divtwo{}\input{main.tex}'
	xelatex '\def\divtwo{}\input{main.tex}'
	mv main.pdf $@

analysis.pdf : analysis.tex $(DEPS) 
	xelatex analysis.tex
	xelatex analysis.tex
	xelatex analysis.tex

.PHONY : ALL div1 div2 clean analysis

.DEFAULT_GOAL = ALL

ALL : njupc-div1.pdf njupc-div2.pdf analysis.pdf

div1 : njupc-div1.pdf
	xdg-open $<

div2 : njupc-div2.pdf
	xdg-open $<

analysis : analysis.pdf
	xdg-open $<

clean:
	rm -rf njupc-div1.pdf njupc-div2.pdf analysis.pdf *.aux *.log *.nav *.out *.snm *.toc
