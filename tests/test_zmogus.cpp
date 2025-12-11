#include <gtest/gtest.h>
#include "../zmogus.h"
#include "../studentas.h"
#include <type_traits>

TEST(ZmogusTest, IsAbstractClass) {
    EXPECT_TRUE(std::is_abstract<Zmogus>::value);
}

TEST(ZmogusTest, HasVirtualDestructor) {
    EXPECT_TRUE(std::has_virtual_destructor<Zmogus>::value);
}

TEST(ZmogusTest, StudentasCanBeInstantiated) {
    Studentas s("Jonas", "Jonaitis");
    EXPECT_EQ(s.getVardas(), "Jonas");
    EXPECT_EQ(s.getPavarde(), "Jonaitis");
}

TEST(ZmogusTest, PolymorphismWorks) {
    Zmogus* ptr = new Studentas("Petras", "Petraitis");
    EXPECT_EQ(ptr->getVardas(), "Petras");
    EXPECT_EQ(ptr->getPavarde(), "Petraitis");
    delete ptr;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}