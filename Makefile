D := # New directory name

ifneq ($(D),)
new:
	mkdir -p $(D)
	cd $(D) && vim
endif

.PHONY: lc
lc:
	nc -l 13013

clean:
	rm .gitignore
	git clean -if
	git checkout .gitignore


ddir := $(filter-out leetcode _archive LICENSE Makefile %.vim,\
		$(wildcard *))
adir := $(patsubst %,_archive/%,$(ddir))

.PHONY: show_ddir
show_ddir:
	$(info $(ddir))
	$(info $(adir))

$(adir): f = $(patsubst _archive/%,%,$@)
$(adir):
	git mv $(f) $@
	git commit -a -m ":truck: _archive $(f), close #" -e
