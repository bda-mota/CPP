#ifdef SPAN_HPP
# define SPAN_HPP


class SPAN {

private:
	unsigned int n;

public:
	Span(void);
	Span(unsigned int n);
	Span( const Span& other );
	Span& operator=( const Span& other );
	~Span(void);

	void	addNumber(unsigned int n);
}

#endif
