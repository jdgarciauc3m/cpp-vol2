$(FINAL_MEMMGMT_PDF): $(MEMMGMT_PARTS) $(CONFIG_INPUT) $(IMG_INPUT)
	$(LATEXMK) -jobname=$(MEMMGMT_BASE) $(MEMMGMT_BASE)/slides.tex

$(FINAL_MEMMGMT_EJ_PDF):	$(MEMMGMT_EJ_PARTS) $(CONFIG_INPUT)
	$(LATEXMK) -jobname=$(MEMMGMT_BASE)-ej $(MEMMGMT_BASE)/ej/hoja-ej.tex
