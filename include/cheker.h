#ifndef CHEKER_H
#define CHEKER_H

class checker
{
private:
    char m_color;
    char m_figure;
    bool m_damka;
public:
    checker(): m_color(' '), m_figure(' '), m_damka(false) {}

    void setColor( char color )
    {
        m_color = color;
    }

    char getColor() const
    {
        return m_color;
    }

    void setFigure( char figure )
    {
        m_figure = figure;
    }

    char getFigure() const
    {
        return m_figure;
    }

    void setStatus( bool stat )
    {
        m_damka = stat;
    }

    bool getStatus()
    {
        return m_damka;
    }

    ~checker() = default;
};

#endif