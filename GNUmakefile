.SUFFIXES: .s
CXXFLAGS=-std=c++11

.cpp.s:
	c++ -S -o $@ $<

all: t_constr.out t_dyn tref
clean:
	rm -f t_constr.out t_dyn tref *.s

t_constr.out: t_constr_a.s t_constr_b.s
	diff $^ > $@; \
	R=$$?; \
	[ $$R -eq 0 -o $$R -eq 1 ]

