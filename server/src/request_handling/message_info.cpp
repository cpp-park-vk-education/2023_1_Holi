//
// Created by Алексей on 02.05.2023.
//

#include <boost/json/src.hpp>

#include "request_handling/message_info.h"


bool operator==(const MessageInfo &l, const MessageInfo &r) {
    return (l.body_ == r.body_) && (l.status_ == r.status_);
}


std::ostream& operator<<(std::ostream& os, const MessageInfo& message) {
    pt::ptree pt;
    std::stringstream ss;
    ss << message.body_;
    pt::read_json(ss, pt);

    std::stack<std::pair<std::string, const pt::ptree*>> stack;
    stack.emplace("", &pt);

    os << "MessageInfo(\n\tbody: {\n";
    while (!stack.empty()) {
        auto [key, node] = stack.top();
        stack.pop();

        for (const auto& child : *node) {
            std::string child_key = child.first;
            std::string full_key = key.empty() ? child_key : key + "." + child_key;

            if (child.second.empty()) {
                os << "\t\t" << full_key << ": " << child.second.data() << std::endl;
            } else {
                stack.emplace(full_key, &child.second);
            }
        }
    }

    os << "\t}\n\tstatus: " << message.status_ << "\n)";

    return os;
}

