$(FINAL_DYNPOL_PDF): $(DYNPOL_PARTS) $(CONFIG_INPUT) $(IMG_INPUT)
	$(LATEXMK) -jobname=$(DYNPOL_BASE) $(DYNPOL_BASE)/slides.tex

$(FINAL_DYNPOL_EJ_PDF):	$(DYNPOL_EJ_PARTS) $(CONFIG_INPUT)
	$(LATEXMK) -jobname=$(DYNPOL_BASE)-ej $(DYNPOL_BASE)/ej/hoja-ej.tex
