#include <iostream>



class RationalNumber {
    public: 
        RationalNumber( unsigned int numerator, unsigned int denominator ) { m_numerator = numerator; m_denominator = denominator; }; 
        
        friend RationalNumber one_over_two_plus( const RationalNumber & other );
        friend RationalNumber plus_one( const RationalNumber & other );

        friend std::ostream& operator<<(std::ostream& os, const RationalNumber& n);
        bool numerator_has_more_digits_than_denominator();
    private: 
        unsigned int m_denominator; 
        unsigned int m_numerator;
};

unsigned int number_of_digits( unsigned int & n){ 
    int k = 1; 
    int trial = n;
    while ( (trial = trial/10) ) { 
        k++;
    }
    return k; 
}

bool RationalNumber::numerator_has_more_digits_than_denominator(){ 

    if ( number_of_digits( this->m_numerator )>number_of_digits( this->m_denominator ) )  { 
        return true;
    }
    return false;
}

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

    int answer{0};

    for ( int i = 0; i<(1000-1); i++ ) { 
        iter =  one_over_two_plus( iter );
        RationalNumber trial = plus_one( iter );
        std::cout<< trial;
        if ( trial.numerator_has_more_digits_than_denominator() ) { 
            std::cout<< "here!" << std::endl;
            answer++;
        }
    }
    std::cout<< "answer" << answer << std::endl; 

}
