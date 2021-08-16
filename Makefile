BUILD_DIR= build
FINAL_DIR= final

LATEXMK=latexmk -pdf -file-line-error -halt-on-error -outdir=$(FINAL_DIR) 

CONFIG_INPUT=config/config-lst.tex \
	     config/config-tc.tex \
	     config/footline.tex \
	     config/packages.tex \
	     $(BUILD_DIR)/date.tex

LOGOS=\
logos/arcos.png \
logos/uc3m.png

include guide/Makefile.def
include 01-noexcept/Makefile.def
include 02-constr-destr/Makefile.def
include 03-copia/Makefile.def

ALL_PARTS= \
$(GUIDE_PARTS) \
$(NOEXCEPT_PARTS) \
$(CONSTRDESTR_PARTS) \
$(COPIA_PARTS) \

ALL_EJ_PARTS= \
$(NOEXCEPT_EJ_PARTS) \
$(CONSTRDESTR_EJ_PARTS) \
$(COPIA_EJ_PARTS) \

ALL_SLIDES_FINAL_PDF= \
$(FINAL_DIR)/$(NOEXCEPT_PDF) \
$(FINAL_DIR)/$(CONSTRDESTR_PDF) \
$(FINAL_DIR)/$(COPIA_PDF) \

ALL_EJ_FINAL_PDF= \
$(FINAL_DIR)/$(NOEXCEPT_EJ_PDF) \
$(FINAL_DIR)/$(CONSTRDESTR_EJ_PDF) \
$(FINAL_DIR)/$(COPIA_EJ_PDF) \

ALL_FINAL_PDF=\
$(FINAL_DIR) \
$(ALL_SLIDES_FINAL_PDF) \
$(ALL_EJ_FINAL_PDF) \
$(GUIDE_FINAL_PDF) \

all:	$(ALL_FINAL_PDF)

clean:
	rm -Rf $(BUILD_DIR)
	rm -Rf $(FINAL_DIR)

build:
	mkdir $(BUILD_DIR)

updatevers:	$(BUILD_DIR)
	git log -1 --format=%ad --date=format:'\date{%B de %Y}' > $(BUILD_DIR)/date.tex
#	git log -1 --format=%ad --date=format:'\date{%d de %B de %Y}' > $(BUILD_DIR)/date.tex

$(FINAL_DIR):
	mkdir $(FINAL_DIR)

include $(GUIDE_BASE)/Makefile.mk
include $(NOEXCEPT_BASE)/Makefile.mk
include $(CONSTRDESTR_BASE)/Makefile.mk
include $(COPIA_BASE)/Makefile.mk
