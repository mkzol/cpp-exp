.SUFFIXES: .s
CXXFLAGS=-std=c++11 -g
CC=g++

.cpp.s:
	c++ -g -S -o $@ $<

all: t_constr.out t_dyn tref main_kv minimal.s t_call.out t_polym t_xref1.o t_xref2.o
clean:
	rm -f *.out *.s *.o t_dyn tref main_kv t_polym

t_call.out: t_call_ref.s t_call_ptr.s
	diff $^ > $@; \
	R=$$?; \
	[ $$R -eq 0 -o $$R -eq 1 ]

t_constr.out: t_constr_a.s t_constr_b.s
	diff $^ > $@; \
	R=$$?; \
	[ $$R -eq 0 -o $$R -eq 1 ]

main_kv: main_kv.o kv.o

