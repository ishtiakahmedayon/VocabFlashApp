#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include <fstream>
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------

__fastcall TForm5::TForm5(TComponent* Owner)
    : TForm(Owner)
{
    currentIndex = -1;
}
//---------------------------------------------------------------------------

// This runs when the form is created (on startup)
void __fastcall TForm5::FormCreate(TObject *Sender)
{
    // Initialize random number generator
    randomize();

    // Load vocabulary from files
    LoadVocabularyFiles();

    // Hide meaning initially
    LabelMeaning->Visible = false;

    // Show first random word
    if (vocabulary.size() > 0) {
        ShowRandomWord();
    } else {
        LabelWord->Caption = "No vocabulary loaded!";
        ShowMessage("Put vocab1.txt, vocab2.txt, vocab3.txt, vocab4.txt in the same folder as the .exe!");
        ButtonReveal->Enabled = false;
        ButtonNext->Enabled = false;
	}
}
//---------------------------------------------------------------------------

// Load words from 3-4 vocabulary files
void TForm5::LoadVocabularyFiles()
{
    // SIMPLE: Only look in C:/Vocab/ folder
    String basePath = "C:/temp/";
    String files[] = {"vocab1.txt", "vocab2.txt", "vocab3.txt", "vocab4.txt"};

    // Load each file
    for (int i = 0; i < 4; i++) {
        String fullPath = basePath + files[i];

        // Try to open the file
        std::ifstream file(AnsiString(fullPath).c_str());

        if (file.is_open()) {
            std::string line;

            // Read each line
            while (std::getline(file, line)) {
                if (line.empty()) continue;

                // Find comma
                size_t comma = line.find(',');

                if (comma != std::string::npos) {
                    // Get word and meaning
                    std::string word = line.substr(0, comma);
                    std::string meaning = line.substr(comma + 1);

                    // Add to list
                    VocabWord entry;
                    entry.word = word.c_str();
                    entry.meaning = meaning.c_str();
                    vocabulary.push_back(entry);
                }
            }
            file.close();
        }
    }

    // Show how many words loaded
    ShowMessage("Loaded " + IntToStr((int)vocabulary.size()) + " words!");
}
//---------------------------------------------------------------------------

// Show a random word from vocabulary
void TForm5::ShowRandomWord()
{
    if (vocabulary.size() == 0) return;

    // Get random index
    currentIndex = random(vocabulary.size());

    // Display the word
    LabelWord->Caption = vocabulary[currentIndex].word;

    // Hide the meaning
    LabelMeaning->Visible = false;
    LabelMeaning->Caption = vocabulary[currentIndex].meaning;

    // Reset button text
    ButtonReveal->Caption = "Reveal Meaning";
}
//---------------------------------------------------------------------------

// Reveal Meaning button clicked
void __fastcall TForm5::ButtonRevealClick(TObject *Sender)
{
    // Toggle visibility of meaning
    LabelMeaning->Visible = !LabelMeaning->Visible;

    // Change button text
    if (LabelMeaning->Visible) {
        ButtonReveal->Caption = "Hide Meaning";
    } else {
        ButtonReveal->Caption = "Reveal Meaning";
    }
}
//---------------------------------------------------------------------------

// Next Word button clicked
void __fastcall TForm5::ButtonNextClick(TObject *Sender)
{
    ShowRandomWord();
}
//---------------------------------------------------------------------------
