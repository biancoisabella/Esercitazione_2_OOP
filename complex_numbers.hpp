#pragma once

// Definisco la nuova classe
template<typename T> requires std::floating_point<T>
class complex_number
{
    /* Attributi privati */
    T real_p; //parte reale
    T img_p; //parte immaginaria

public:
    /* METODI PUBBLICI */

    /* ---- Costruttori ---- */

    // costruttore di default che inizializza sia la parte reale sia la parte immaginaria a 0
    complex_number()
        : real_p (0), img_p(0)
    {}

    // costruttore user-defined
    complex_number(T real_part, T imaginary_part)
        : real_p(real_part), img_p(imaginary_part)
    {}

    // costruttore user-defined nel caso in cui passo solo la parte reale o immaginaria
    complex_number(T value, bool is_real=true)
        : real_p(value*is_real), img_p(value*(!is_real))
    {}

    /* -------------------------- */

    /* FUNZIONI */

    // Funzione get della parte reale
    T get_real_p(void) const {
        return real_p;
    }

    // Funzione get della parte immaginaria
    T get_img_p(void) const {
        return img_p;
    }

    // Funzione per ottenere il coniugato
    complex_number<T> get_complex_conjugate() const {
        return complex_number<T>(real_p, -img_p);
    }

    /* OVERLOAD */

    //              ---- SOMMA ----
    // Somma +=
    complex_number& operator+=(const complex_number& other) {
        real_p = real_p + other.real_p; // sommo le parti reali
        img_p = img_p + other.img_p; // sommo le parti immaginarie 
        return *this;
	}


    // Somma + 
    complex_number operator+(const complex_number& other) const {
        complex_number c = *this;
        c += other;
        return c;
    }

    // Somma con un tipo T reale +=
    complex_number& operator+=(const T& other) {
        real_p = real_p + other; // sommo le parti reali
        return *this;
	}


    // Somma con un tipo T reale + 
    complex_number operator+(const T& other) const {
        complex_number c = *this;
        c += other;
        return c;
    }

    //              --------------


    //              ---- PRODOTTO ----
    // Prodotto *=
    complex_number& operator*=(const complex_number& other) {
        T a = real_p;
        T b = img_p;

        T c = other.real_p;
        T d = other.img_p;

        real_p = a*c - b*d; // sommo le parti reali
        img_p = b*c + a*d; // sommo le parti immaginarie 
        return *this;
	}


    // Prodotto * 
    complex_number operator*(const complex_number& other) const {
        complex_number c = *this;
        c *= other;
        return c;
    }

    // Prodotto con un tipo T reale *=
    complex_number& operator*=(const T& other) {
        real_p = real_p*other; // sommo le parti reali
        img_p = img_p*other;
        return *this;
	}


    // Prodotto con un tipo T reale * 
    complex_number operator*(const T& other) const {
        complex_number c = *this;
        c *= other;
        return c;
    }

    //              --------------

};

    // Overload dell'operatore somma a sinistra (qunidi T + COMPLEX)
    template<typename T>
        complex_number<T>
        operator+(const T& t, const complex_number<T>& c)
        {
            return c + t;
    }

    // Overload dell'operatore prodotto a sinistra (qunidi T * COMPLEX)
    template<typename T>
        complex_number<T>
        operator*(const T& t, const complex_number<T>& c)
        {
            return c * t;
    }


    // Overload of <<, to make the rationals printable. 
    template<typename T>
    std::ostream&
    operator<<(std::ostream& os, const complex_number<T>& c) {

        // Se la parte immaginaria è 0 stampo la reale
        if (c.get_img_p() == 0)
            os << c.get_real_p();
        else if (c.get_real_p() == 0)
            os << c.get_img_p() << "i";
        else{
            os << c.get_real_p();
            if(c.get_img_p() > 0)
                os << "+";
            os << c.get_img_p() << "i";
        }
        return os;
    }

