#ifndef Unit5H
#define Unit5H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <vector>
//---------------------------------------------------------------------------

struct VocabWord {
    String word;
    String meaning;
};

class TForm5 : public TForm
{
__published:
    TLabel *LabelWord;
    TLabel *LabelMeaning;
    TButton *ButtonReveal;
    TButton *ButtonNext;
    TLabel *LabelTitle;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall ButtonRevealClick(TObject *Sender);
    void __fastcall ButtonNextClick(TObject *Sender);

private:
    std::vector<VocabWord> vocabulary;
    std::vector<int> shuffledIndices;
    int currentIndex;
    int shufflePosition;

    void LoadVocabularyFiles();
    void ShowRandomWord();
    void ShuffleWords();

public:
    __fastcall TForm5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif
