DSK = $(NAME).dsk

# For this one, see https://applecommander.github.io/
AC ?= $(HOME)/Documents/apple2/AppleCommander/ac.jar
ACX ?= $(HOME)/Documents/apple2/AppleCommander/acx.jar

# Unix or Windows
ifeq ($(shell echo),)
    CP = cp $1
else
    CP = copy $(subst /,\,$1)
endif

REMOVES += $(DSK)

.PHONY: dsk
dsk: $(DSK)

$(DSK): $(NAME).apple2
	# Below commented lines are to original recommended cc65 dsk build options.
	# $(call CP, apple2/template.dsk $@)
	# java -jar $(AC) -p  $@ $(NAME).system sys < $(shell cl65 --print-target-path)/apple2/util/loader.system
	java -jar $(ACX) create -d $(NAME).dsk --format apple2/template.dsk --prodos --size=140kb
	java -jar $(AC) -as $(NAME).dsk $(NAME) bin < $(NAME).apple2
