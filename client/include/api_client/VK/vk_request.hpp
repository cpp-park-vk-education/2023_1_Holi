#include "request.hpp"
#include <memory>

class VKRequest : public Request {
public:
    VKRequest(){}

    void execute() override;
};
