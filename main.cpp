#include <iostream>



class RationalNumber {
    public: 
        RationalNumber( int numerator, int denominator ) { m_numerator = numerator; m_denominator = denominator; }; 
        
        friend RationalNumber one_over_two_plus( const RationalNumber & other );
        friend RationalNumber plus_one( const RationalNumber & other );

        friend std::ostream& operator<<(std::ostream& os, const RationalNumber& n);
    private: 
        int m_denominator; 
        int m_numerator;
};

RationalNumber one_over_two_plus( const RationalNumber & other ) { 
    return RationalNumber( other.m_denominator, 2*other.m_denominator+other.m_numerator ); 
}

RationalNumber plus_one( const RationalNumber & other ) { 
    return RationalNumber( other.m_numerator+other.m_denominator, other.m_denominator );
}

std::ostream& operator<<(std::ostream& os, const RationalNumber& n){ 
    os << n.m_numerator << '/' << n.m_denominator << std::endl;
    return os;
}


int main()
{

    RationalNumber iter(1,2); 

    for ( int i = 0; i<10; i++ ) { 
        iter =  one_over_two_plus( iter );
        RationalNumber trial = plus_one( iter );
        std::cout<< trial;
    }
}
