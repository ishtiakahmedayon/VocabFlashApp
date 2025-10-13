object Form5: TForm5
  Left = 0
  Top = 0
  Caption = 'Vocabulary Flashcards'
  ClientHeight = 461
  ClientWidth = 584
  Color = clCream
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  OnCreate = FormCreate
  TextHeight = 15
  object LabelTitle: TLabel
    Left = 150
    Top = 30
    Width = 256
    Height = 32
    Alignment = taCenter
    Caption = 'Vocabulary FlashCards'
    Color = clSkyBlue
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    Transparent = False
  end
  object LabelWord: TLabel
    Left = 100
    Top = 125
    Width = 399
    Height = 45
    Alignment = taCenter
    AutoSize = False
    Caption = 'Click "Next Word" to Start'
    Color = clMoneyGreen
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -32
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    Transparent = False
    WordWrap = True
  end
  object LabelMeaning: TLabel
    Left = 100
    Top = 230
    Width = 400
    Height = 80
    Alignment = taCenter
    AutoSize = False
    Caption = 'Meaning will appear here...'
    Color = clKhaki
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -24
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    Transparent = False
    Visible = False
    WordWrap = True
  end
  object ButtonReveal: TButton
    Left = 100
    Top = 380
    Width = 180
    Height = 50
    Caption = 'Reveal Meaning'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    OnClick = ButtonRevealClick
  end
  object ButtonNext: TButton
    Left = 320
    Top = 380
    Width = 180
    Height = 50
    Caption = 'Next Word'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = ButtonNextClick
  end
end
