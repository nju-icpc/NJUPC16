main.pdf : $(shell find -type f -name "*.tex")
	xelatex main.tex
	xelatex main.tex

open: | main.pdf
	xdg-open main.pdf

clean:
	rm -rf main.pdf

