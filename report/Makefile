start:
	latexmk --shell-escape -synctex=1 -interaction=nonstopmode -file-line-error -pdf -outdir=. main.tex

clean:
	find . -maxdepth 1 -type f | cut -d '/' -f 2 | awk '/.*(acn|acr|alg|aux|bbl|blg|latexmk|fls|glg|glo|gls|lof|log|lot|out|toc)/ {print}' | xargs rm



