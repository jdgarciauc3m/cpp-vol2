$(FINAL_STL_PDF): $(STL_PARTS) $(CONFIG_INPUT) $(IMG_INPUT)
	$(LATEXMK) -jobname=$(STL_BASE) $(STL_BASE)/slides.tex

$(FINAL_STL_EJ_PDF):	$(STL_EJ_PARTS) $(CONFIG_INPUT)
	$(LATEXMK) -jobname=$(STL_BASE)-ej $(STL_BASE)/ej/hoja-ej.tex
