#include "bookPtr.h"
#include <memory>
int main()
{
    using namespace jangseoyeon2649035;

    bookPtr bp1;
    bookPtr bp2{bp1};
    bookPtr bp3{std::move(bp2)};
    bp2= std::move(bp3);
    bp3=bp2;

    bookPtr* bp{new bookPtr{book{}}};
    delete bp;

    std::unique_ptr<bookPtr> up1;
    auto up2{std::make_unique<bookPtr>(book{"title",1,10000})};
    up1=std::move(up2);
    up1->print();
    auto sp1{std::make_shared<bookPtr>(book{"shared",2,20000})};
    std::shared_ptr<bookPtr> sp2{sp1};
    std::cout << sp1.use_count()<< " "<< sp1.use_count()<<std::endl;
    std::weak_ptr<bookPtr> wp1{sp1};
    std::cout << sp1.use_count()<< " "<< sp1.use_count()<<std::endl;
    sp1.reset();
    std::cout << sp1.use_count()<< " "<< sp2.use_count()<<std::endl;
    if(!wp1.expired()) sp1= wp1. lock();
    std::cout << sp1.use_count()<< " "<< sp2.use_count()<<std::endl;
    delete bp;
    return 0;
}