
target = client 
src = $(shell find . -name "*.cpp")
inc = $(shell find ../inc -name "*.h")
obj = $(src:%.cpp=%.o)
libs = -lpthread

ALL = $(target)
$(target) : $(obj)
	g++ $(obj) -o $(target) $(libs)

%.o : %.cpp $(inc)
	g++ -c $< -o $@

.PHONY : clean
clean:
	-rm -rf $(ALL) $(obj)
	    
