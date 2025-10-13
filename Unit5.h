//---------------------------------------------------------------------------
#ifndef Unit5H
#define Unit5H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <vector>
//---------------------------------------------------------------------------

// Simple structure to hold word and meaning
struct VocabWord {
    String word;
    String meaning;
};

class TForm5 : public TForm
{
__published:	// IDE-managed Components
    TLabel *LabelWord;
    TLabel *LabelMeaning;
    TButton *ButtonReveal;
    TButton *ButtonNext;
    TLabel *LabelTitle;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall ButtonRevealClick(TObject *Sender);
    void __fastcall ButtonNextClick(TObject *Sender);

private:	// User declarations
    std::vector<VocabWord> vocabulary;  // Store all words here
    int currentIndex;                    // Current word index

    void LoadVocabularyFiles();          // Load words from files
    void ShowRandomWord();               // Display a random word

public:		// User declarations
    __fastcall TForm5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif

