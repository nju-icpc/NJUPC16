DEPS = $(shell find src) 

main.pdf : main.tex $(DEPS)
	xelatex main.tex
	xelatex main.tex

open: | main.pdf
	xdg-open main.pdf

clean:
	rm -rf main.pdf main.aux main.log
