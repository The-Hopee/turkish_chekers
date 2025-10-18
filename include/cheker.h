#ifndef CHEKER_H
#define CHEKER_H

class checker
{
private:
    int m_type; // type of chekers
    char m_color;
    char m_figure;
public:
    checker(): m_type(-1), m_color(' '), m_figure(' ') {}

    void setType( int type )
    {
        m_type = type;
    }

    int getType() const
    {
        return m_type;
    }

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

    ~checker() = default;
};

#endif