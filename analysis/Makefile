.PHONY: open clean

open: main.pdf
	xdg-open $<

main.pdf: main.tex
	xelatex main
	xelatex main

clean:
	rm -rf main.pdf


