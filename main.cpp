#include <iostream>
#include <sstream>


#include <NTL/ZZ.h>

using namespace NTL;

template <typename T> class RationalNumber {
    public: 
        RationalNumber( T numerator, T denominator ) { m_numerator = numerator; m_denominator = denominator; }; 
        
        template <typename S> 
        friend RationalNumber<S> one_over_two_plus( const RationalNumber<S> & other );
        template <typename S> 
        friend RationalNumber<S> plus_one( const RationalNumber<S> & other );
        template <typename S>
        friend std::ostream& operator<<(std::ostream& os, const RationalNumber<S>& n);
        bool numerator_has_more_digits_than_denominator();
    private: 
        T m_denominator; 
        T m_numerator;
};

namespace BoilerPlaceCode {     
    std::string conver_to_string( const ZZ & number ) { 
        std::ostringstream os;
        os << number; 
        std::string s = os.str();
        return s; 
    }
}


template <typename T> size_t number_of_digits( const T & n){ 
    std::string s = std::to_string(n); 
    return s.length(); 
};

template<>        // specialization for T = ZZ
size_t number_of_digits( const ZZ & n ){ 
    std::string s = BoilerPlaceCode::conver_to_string(n); 
    return s.length();
}

template <typename T> 
bool RationalNumber<T>::numerator_has_more_digits_than_denominator(){ 

    if ( number_of_digits( this->m_numerator )>number_of_digits( this->m_denominator ) )  { 
        return true;
    }
    return false;
}

template <typename T> 
RationalNumber<T> one_over_two_plus( const RationalNumber<T> & other ) { 
    return RationalNumber<T>( other.m_denominator, 2*other.m_denominator+other.m_numerator ); 
}

template <typename T> 
RationalNumber<T> plus_one( const RationalNumber<T> & other ) { 
    return RationalNumber<T>( other.m_numerator+other.m_denominator, other.m_denominator );
}

template <typename T> 
std::ostream& operator<<(std::ostream& os, const RationalNumber<T>& n){ 
    os << n.m_numerator << '/' << n.m_denominator << std::endl;
    return os;
}


int main()
{

    RationalNumber<ZZ> iter(to_ZZ(1),to_ZZ(2)); 

    int answer{0};

    for ( int i = 2; i<=(1000); i++ ) { 
        iter =  one_over_two_plus( iter );
        auto trial = plus_one( iter );
        std::cout << i << " " << trial;
        if ( trial.numerator_has_more_digits_than_denominator() ) { 
            std::cout<< "here!" << std::endl;
            answer++;
        }
    }
    std::cout<< "answer" << answer << std::endl; 

}
