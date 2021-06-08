
#ifndef INC_32_EX3_312391774_SHRINKINGDISC_H
#define INC_32_EX3_312391774_SHRINKINGDISC_H


#include "Disc.h"

class ShrinkingDisc: public Disc {
public:
    ShrinkingDisc(double x1, double y1, double vx, double vy, double radius,int lives_count=0,bool is_Shrank= false);
    ShrinkingDisc(const ShrinkingDisc& other);
    ShrinkingDisc &operator=(const ShrinkingDisc& rhs);
    virtual ~ShrinkingDisc(){};
    void shrink(); // shrinking the disc
    virtual ShrinkingDisc* clone() const;
    int getLivesCount() const; // returns lives count
    void setLivesCount(int livesCount); // setter for lives count
    virtual Disc_Type getDiscType() const;
    bool isShrank() const; // flag the tell if the disc already shrank
    // prints the disc by (X,Y) / radius
    friend std::ostream &operator<<(std::ostream &os, const ShrinkingDisc &sd);
private:
    int lives_count; // indicates the times the disc bumped, an 0<int<3
    bool is_Shrank; // flag to indicate if the disc already shrinked once.
    Disc_Type discType;
};


#endif //INC_32_EX3_312391774_SHRINKINGDISC_H
