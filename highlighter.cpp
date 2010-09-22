#include "highlighter.h"

Highlighter::Highlighter(QObject *parent) :
    QSyntaxHighlighter(parent)
{
    HighlightingRule rule;
    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns;
    keywordPatterns <<"\\bchar\\b";
    foreach(const QString &pattern,keywordPatterns){
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }
}

void Highlighter::highlightBlock(const QString &text)
{

}
