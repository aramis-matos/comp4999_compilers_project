# This Makefile is designed to be simple and readable.  It does not
# aim at portability.  It requires GNU Make.

BISON = bison
CXX = g++
FLEX = flex

all: avismo

%.cc %.hh: %.yy
	$(BISON) $(BISONFLAGS) -o $*.cc $<

%.cc: %.ll
	$(FLEX) $(FLEXFLAGS) -o$@ $<

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o$@ $<

avismo: avismo.o driver.o parser.o scanner.o
	$(CXX) -o $@ $^

avismo.o: parser.hh
parser.o: parser.hh
scanner.o: parser.hh

clean:
	rm -f avismo *.o parser.hh parser.cc scanner.cc
