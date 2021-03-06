#ifndef _PGTYPETHREE_HPP
#define _PGTYPETHREE_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <chessmind/pgn/PGNotation.hpp>

class PGNotationType3 implements PGNotationInterface
{
    friend std::ostream& operator<<(std::ostream& out, const PGNotationType3& obj);
    friend std::istream& operator>>(std::istream& in, PGNotationType3& obj);

    char _piece;
    const std::string _original;
    std::string _san;

public:
    PGNotationType3() {};
    PGNotationType3(const std::string& san) : _original(san)
    {
        std::stringstream ss;
        ss << san;
        ss >> *this;
    };
    virtual bool equals(const PGNotationInterface& a)
    {
        return (san() == a.san() && piece() == a.piece());
    };
    virtual bool equals(const std::string& a)
    {
        std::stringstream ss;
        ss << *this;
        std::string text;
        ss >> text;
        return text == a;
    };

    inline char piece() const { return _piece; }
    inline const std::string& san() const { return _san; }
    virtual bool castle() const { return false; }
    virtual bool kingCastle() const { return false; }
    virtual bool queenCastle() const { return false; }
    virtual bool gameover() const { return false; }
    virtual int type() const { return 3; }
    virtual const std::string& original() const { return _original; }
    virtual std::string resolve(const MovesTable& intersections, const std::string& black_or_white_set, const ChessBoard* board) const;
    virtual bool promotion() const { return false; }
};

#endif // _PGTYPETHREE_HPP
