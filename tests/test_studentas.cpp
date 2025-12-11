#include <gtest/gtest.h>
#include "../studentas.h"

TEST(StudentasTest, DefaultConstructor) {
    Studentas s;
    EXPECT_EQ(s.getVardas(), "");
    EXPECT_EQ(s.getPavarde(), "");
    EXPECT_EQ(s.getEgzaminas(), 0);
    EXPECT_DOUBLE_EQ(s.getBalasVid(), 0.0);
}

TEST(StudentasTest, ConstructorWithParameters) {
    Studentas s("Jonas", "Jonaitis");
    EXPECT_EQ(s.getVardas(), "Jonas");
    EXPECT_EQ(s.getPavarde(), "Jonaitis");
}

TEST(StudentasTest, CopyConstructor) {
    Studentas s1("Petras", "Petraitis");
    s1.setEgzaminas(8);
    s1.addNamuDarbas(7);
    s1.addNamuDarbas(9);
    
    Studentas s2(s1);
    EXPECT_EQ(s2.getVardas(), "Petras");
    EXPECT_EQ(s2.getPavarde(), "Petraitis");
    EXPECT_EQ(s2.getEgzaminas(), 8);
    EXPECT_EQ(s2.getNamudarbai().size(), 2);
}

TEST(StudentasTest, AssignmentOperator) {
    Studentas s1("Jonas", "Jonaitis");
    s1.setEgzaminas(10);
    
    Studentas s2;
    s2 = s1;
    
    EXPECT_EQ(s2.getVardas(), "Jonas");
    EXPECT_EQ(s2.getPavarde(), "Jonaitis");
    EXPECT_EQ(s2.getEgzaminas(), 10);
}

TEST(StudentasTest, AddingHomework) {
    Studentas s("Test", "Student");
    s.addNamuDarbas(5);
    s.addNamuDarbas(7);
    s.addNamuDarbas(9);
    
    EXPECT_EQ(s.getNamudarbai().size(), 3);
    EXPECT_EQ(s.getNamudarbai()[0], 5);
    EXPECT_EQ(s.getNamudarbai()[1], 7);
    EXPECT_EQ(s.getNamudarbai()[2], 9);
}

TEST(StudentasTest, CalculateAverage) {
    Studentas s("Test", "Student");
    s.addNamuDarbas(8);
    s.addNamuDarbas(9);
    s.addNamuDarbas(7);
    s.setEgzaminas(10);
    s.skaiciuotiVidurki();
    
    EXPECT_DOUBLE_EQ(s.getBalasVid(), 9.2);
}

TEST(StudentasTest, ComparisonOperators) {
    Studentas s1("A", "B");
    s1.setBalasVid(7.5);
    
    Studentas s2("C", "D");
    s2.setBalasVid(8.5);
    
    EXPECT_TRUE(s1 < s2);
    EXPECT_TRUE(s2 > s1);
}

TEST(StudentasTest, EqualityOperator) {
    Studentas s1("Jonas", "Jonaitis");
    Studentas s2("Jonas", "Jonaitis");
    Studentas s3("Petras", "Petraitis");
    
    EXPECT_TRUE(s1 == s2);
    EXPECT_FALSE(s1 == s3);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}