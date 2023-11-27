#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include <string>
#include "../Project1/Source.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;


TEST_CLASS(UnitTest1)
{
public:

    TEST_METHOD(TestMethod1)
    {
        // Arrange
        char* inputFileName = "testInput.txt";
        char* outputFileName = "testOutput.txt";
        ofstream testInputFile(inputFileName);
        testInputFile << "Hello, World! 123";
        testInputFile.close();

        // Act
        ProcessBIN(inputFileName, outputFileName);

        // Assert
        ifstream testOutputFile(outputFileName);
        string output((istreambuf_iterator<char>(testOutputFile)), istreambuf_iterator<char>());
        Assert::AreEqual(string("HelloWorld"), output);
    }
};


