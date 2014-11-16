.SUFFIXES: .s

.cpp.s:
	g++ -S -o $@ $<

all: t_constr.out t_dyn

t_constr.out: t_constr_a.s t_constr_b.s
	diff $^ > $@

