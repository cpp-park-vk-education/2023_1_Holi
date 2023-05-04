
#ifndef REQUESTMAKER_H
#define REQUESTMAKER_H

#include <QString>

class IRequestMaker
{
public:
    IRequestMaker();
    virtual QString  Get(){return "0";}
};

#endif // REQUESTMAKER_H
