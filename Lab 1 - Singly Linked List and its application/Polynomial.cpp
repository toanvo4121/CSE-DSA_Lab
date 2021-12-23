class Polynomial;
class Term {
private:
    double coeff;   
    int exp;
    friend class Polynomial;
public:
    Term(double coeff = 0.0, int exp = 0) {
        this->coeff = coeff;
        this->exp = exp;
    }
    bool operator==(const Term& rhs) const {
        return this->coeff == rhs.coeff && this->exp == rhs.exp;
    }
    friend ostream & operator<<(ostream &os, const Term& term) {
        cout << endl;
        cout << "Term: " << "(" << term.coeff << " " << term.exp << ")";
        return os;
    }
};
class Polynomial {
private:
    SLinkedList<Term>* terms;
public:
    Polynomial() {
        this->terms = new SLinkedList<Term>();
    }
    ~Polynomial() {
        this->terms->clear();
    }
    void insertTerm(const Term& term);
    void insertTerm(double coeff, int exp);
    void print() {
        SLinkedList<Term>::Iterator it;
        cout << "[";
        for (it = this->terms->begin(); it != this->terms->end(); it++) {
            cout << (*it);
        }
        cout << endl << "]";
    }
};

void Polynomial::insertTerm(const Term &term)
{
    // STUDENT ANSWER
    if (term.coeff == 0) return;
    if (this->terms->size() == 0)
        this->terms->add(term);
    else
    {
        int i = 0;
        for (SLinkedList<Term>::Iterator it = this->terms->begin(); it != this->terms->end(); ++it)
        {
            if (term.exp == (*it).exp)
            {
                (*it).coeff += term.coeff;
                if ((*it).coeff == 0) 
                    it.remove();
                break;
            }
            else if (term.exp > (*it).exp)
            {
                this->terms->add(i, term);
                break;
            }
            else if (i == this->terms->size() - 1) {
                this->terms->add(term);
                break;
            }
            ++i;
        }
    }
}

void Polynomial::insertTerm(double coeff, int exp)
{
    // STUDENT ANSWER
    Term tempTerm(coeff, exp);
    this->insertTerm(tempTerm);
}