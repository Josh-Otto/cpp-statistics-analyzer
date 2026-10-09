// Project2.cpp

// Coder: Joshua Otto 1336412

// NOTE:    There was a bit of confusion with the order of calculations and the missleading of information 
//          displayed if you changed the max and min value before output with the logarithmic function
//          since the range would be displayed as a very different number than the range of the updated 
//          log dataset


#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <chrono>
#include <cmath>
#include "sort.h"

using namespace std;

struct buckets {
      char c = ' ';
      double percent = 0;
      double start = 0;
      double end = 0;
      int count = 0;
};

//       ---- DOUBLE LINES ----
    //STRAIGHTS
string vert = "\xBA";
string horz = "\xCD\xCD\xCD\xCD\xCD";
string horz1 = "\xCD";
//RIGHT CORNERS
string trc = "\xBB";
string brc = "\xBC";
//LEFT CORNERS
string tlc = "\xC9";
string blc = "\xC8";


//       ---- SMALL LINES ----
//STAIGHTS
string smhorz = "\xC4\xC4\xC4\xC4\xC4";
string smhorz1 = "\xC4";
string smvert = "\xB3";
//SMALL RIGHT CORNERS
string smtrc = "\xBF";
string smbrc = "\xD9";
//SMALL LEFT CORNERS
string smtlc = "\xDA";
string smblc = "\xC0";

//SMALL BOTTOM TICK
string smbt = "\xC1";
//SMALL TOP TICK
string smtt = "\xC2";

//       ---- SYMBOLS ----
string blk = "\xDC"; //DF, DC, DB

// ---------------------- RESTORE CODEPAGE ---------------------- 
static void restoreCodePage(UINT codepage)
{
      SetConsoleOutputCP(codepage);
}

// ---------------------- OUTPUTS FREQUENCY TABLE ---------------------- 
void frequencyTableRows(const buckets& group) 
{
      if(group.c == 'A')
      {
            cout << endl << "Frequency Table:" << endl;
            cout << smhorz+smhorz+smhorz+smhorz+smhorz+smhorz+smhorz+smhorz+smhorz+smhorz+smhorz+smhorz+smhorz+smhorz;
      }
      printf("\n\t%c [%8.3f .. %8.3f ] = %7d : %6.3f%%",group.c,group.start,group.end,group.count,group.percent);
      if(group.c == 'J')
      {
            cout << endl;
      }
}

// ---------------------- OUTPUTS FREQUENCY CHART ---------------------- 
void frequencyChartRows(const buckets& group,int numberCounter) 
{
      if(group.c == 'A')
      {
            cout << endl << "Frequency Graph:" << endl;
            cout << smhorz+smhorz+smhorz+smhorz+smhorz+smhorz+smhorz+smhorz+smhorz+smhorz+smhorz+smhorz+smhorz+smhorz+smhorz+smhorz+smhorz << endl;
            cout << "Grp\t % 0   2.5   5.0   7.5  10.0  12.5  15.0  17.5  20.0  22.5  25.0  27.5  30.0" << endl;
            cout << smhorz+smhorz << " " << smtlc+smhorz+smtt+smhorz+smtt+smhorz+smtt+smhorz+smtt+smhorz+smtt+smhorz+smtt+smhorz+smtt+smhorz+smtt+smhorz+smtt+smhorz+smtt+smhorz+smtt+smhorz+smtt << endl;
      }
      cout << group.c << " ";
      if((group.count/(float)numberCounter)*100.0 < 10)
            printf("  %.2f%% ",(group.count/(float)numberCounter)*100.0);
      else
            printf(" %.2f%% ",(group.count/(float)numberCounter)*100.0);
      cout << " "+smvert;
      for(int i = 0; i < group.percent*2.38; i++)
            cout << blk;
      cout << endl;
      if(group.c == 'J')
      {
            cout << smhorz+smhorz << " " << smblc+smhorz+smbt+smhorz+smbt+smhorz+smbt+smhorz+smbt+smhorz+smbt+smhorz+smbt+smhorz+smbt+smhorz+smbt+smhorz+smbt+smhorz+smbt+smhorz+smbt+smhorz+smbt << endl;
      }
}




// BEGINNING OF MAIN
int main()
{
      vector<double> data;
      vector<buckets> groups(10);

      string input;
      double value;
      UINT codepage = GetConsoleOutputCP();
      SetConsoleOutputCP(850);
      double runningTotal{0};
      double totalOfSquares{0};
      int numberCounter{0};
      double smallestValue{INT_MAX};
      double largestValue{-INT_MAX};
      char exitCase[] = "end";


      // ------------------ READ INPUT ------------------ 
      while(cin >> input)
      {
            if(input == "end")
                  break;

            try
            {
                  value = stod(input);
                  data.push_back(value);
                  numberCounter++;
                  runningTotal += value;
                  totalOfSquares += value * value;

                  // find smallest value
                  if(value < smallestValue) 
                  {
                        smallestValue = value; 
                  }

                  // find largest value
                  if(value > largestValue)
                  {
                        largestValue = value; 
                  }

            } catch(...) {}
      }

      // ------------------ SORT ------------------ 
      if(!data.empty())
      {
            quickSort( data, 0, data.size() - 1);
      }

      // SAMPLE OUTPUT FOR TESTING
      //for(double x : data)
      //{
      //      cout << x << " ";
      //}


      // ---------------------------------- FINDING MEDIAN ---------------------------------- 
      //Variables for both cases
      double medianValue;
      // CASE ONE - ODD SET
      if(numberCounter%2 == 1)
      {
            medianValue = data[(numberCounter/2)+1];
      }
      // CASE TWO - EVEN SET
      else
      {
            medianValue = (data[(numberCounter/2)] + data[(numberCounter/2)+1]) /2;
      }
      // -- done with median --

      // ---------------------------------- FINDING THE MEAN ----------------------------------
      double mean = runningTotal / numberCounter;
      // -- done with mean --


      // ---------------------------------- FINDING THE VARIANCE ----------------------------------
      // Iterates through vector array and squares the number in data[i]
      for(int i : data) { totalOfSquares += data[i]*data[i]; }
      // Calculation for variance
      double variance = (totalOfSquares / numberCounter) - (mean * mean);
      // -- Done with variance --


      // ---------------------------------- FINDING THE VARIANCE ----------------------------------
      double standardDeviation = sqrt(variance);
      // -- Done with variance --


      // ---------------------------------- LOGARITHMIC TRANSFORM ----------------------------------
      for(double &x : data)
      {
            if(x > 0)
            {
                  x = log(x);
            } else
            {
            }
      }
      // -- end of log -- 

      double smallestValue2 = data[0];
      double largestValue2 = data[data.size()-1];

      // ---------------------------------- DEFINING BUCKETS ----------------------------------
      double bucketSizes = (largestValue2-smallestValue2)/10;
      // MANUALLY INPUTTING DATA IS SAFEST AND EASIEST
      groups[0].start = smallestValue2-0.0001;
      groups[0].end = smallestValue2+bucketSizes;
      groups[0].c = 'A';
      groups[1].start = smallestValue2+bucketSizes;
      groups[1].end = smallestValue2+bucketSizes*2;
      groups[1].c = 'B';
      groups[2].start = smallestValue2+bucketSizes*2;
      groups[2].end = smallestValue2+bucketSizes*3;
      groups[2].c = 'C';
      groups[3].start = smallestValue2+bucketSizes*3;
      groups[3].end = smallestValue2+bucketSizes*4;
      groups[3].c = 'D';
      groups[4].start = smallestValue2+bucketSizes*4;
      groups[4].end = smallestValue2+bucketSizes*5;
      groups[4].c = 'E';
      groups[5].start = smallestValue2+bucketSizes*5;
      groups[5].end = smallestValue2+bucketSizes*6;
      groups[5].c = 'F';
      groups[6].start = smallestValue2+bucketSizes*6;
      groups[6].end = smallestValue2+bucketSizes*7;
      groups[6].c = 'G';
      groups[7].start = smallestValue2+bucketSizes*7;
      groups[7].end = smallestValue2+bucketSizes*8;
      groups[7].c = 'H';
      groups[8].start = smallestValue2+bucketSizes*8;
      groups[8].end = smallestValue2+bucketSizes*9;
      groups[8].c = 'I';
      groups[9].start = smallestValue2+bucketSizes*9;
      groups[9].end = largestValue2;
      groups[9].c = 'J';
      //  -- end of buckets array (groups) -- 

      // SETTING UP BUCKETS PERCENTS
      int groupID{0};
      int i{0};
      for (double &x : data)
      {
            if(x > groups[groupID].start && x <= groups[groupID].end)
            {
                  groups[groupID].count++;
                  i++;
                  if(i >= data.size()-1)
                  {
                        groupID++;
                        break;
                  }
            } else
            {
                  groupID++;
            }
            if(groupID == 10)
                  break;
      }
      for(auto &group : groups)
      {
            group.percent = (group.count / (double)numberCounter) * 100.0;
      }
      
      // ===============================                                             ===================================
      // ===============================              OUTPUT    SECTION              ===================================
      // ===============================                                             ===================================

      cout << endl;
      cout << tlc+horz+horz+horz+horz+horz+horz+horz+horz+horz1+horz1+trc << endl;
      cout << vert;
      printf("       numberCounter =  %14d    ",numberCounter);
      cout << vert << endl << vert;
      printf("      smallest value =  %14.3f    ",smallestValue);
      cout << vert << endl << vert;
      printf("       largest value =  %14.3f    ",largestValue);
      cout << vert << endl << vert;
      printf("     range of values =  %14.3f    ",largestValue-smallestValue);
      cout << vert << endl << vert;
      printf("        runningTotal =  %14.3f    ",runningTotal);
      cout << vert << endl << vert;
      printf("              median =  %14.3f    ",medianValue);
      cout << vert << endl << vert;
      printf("                mean =  %14.3f    ",mean);
      cout << vert << endl << vert;
      printf("            variance =  %14.3f    ",variance);
      cout << vert << endl << vert;
      printf("  standard deviation =  %14.3f    ",standardDeviation);
      cout << vert << endl;
      cout << blc+horz+horz+horz+horz+horz+horz+horz+horz+horz1+horz1+brc << endl;


      // ----------------------------------------- FREQUENCY TABLE ----------------------------------------- 
      cout << endl;
      for(const auto& group : groups)
      {
            frequencyTableRows(group);
      }


      // ----------------------------------------- FREQUENCY CHART ----------------------------------------- 
      cout << endl;
      for(const auto& group : groups)
      {
            frequencyChartRows(group,numberCounter);
      }


      // LAST LINE(S)
      SetConsoleOutputCP(codepage);

}// END OF MAIN

// link to exe file - Project2
//    Path of exe:            C:\C++ Coding Projects\Project2\x64\Debug\
//    Using Input File:       Project2 < C:\Users\jotto\Downloads\3d10_1M.txt
// 
// CONSOLE COMMAND 'chcp' to reset codepage to code page 437
// 
// #include <Windows.h>
// Code Page 850 character conversion = '\x (HEX VALUE)'
// 