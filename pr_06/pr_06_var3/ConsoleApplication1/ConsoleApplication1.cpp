import pandas as pd
from fuzzywuzzy import fuzz

import text_analiz
from natasha import NamesExtractor

# from natasha.markup import show_markup, show_json


if __name__ == "__main__":
columns = ['safeguards_txt', 'pd_category', 'pd_handle',
'category_sub_txt', 'actions_category', 'stop_condition']
df = pd.read_csv("gdata_edu.csv", encoding = 'utf-8')
text = df.loc[:, ["safeguards_txt"]]
text = text.values.tolist()
stext = text
text = text[3][0]
print(text)
# ---
from natasha import(
    Segmenter,
    NewsEmbedding,
    NewsMorphTagger,
    NewsSyntaxParser,
    Doc
    )

    segmenter = Segmenter()

    emb = NewsEmbedding()
    morph_tagger = NewsMorphTagger(emb)
    syntax_parser = NewsSyntaxParser(emb)
    doc = Doc(text)

    doc.segment(segmenter)
    doc.tag_morph(morph_tagger)
    doc.parse_syntax(syntax_parser)

    sent = doc.sents[2]
    sent.morph.print()

    from natasha import NewsNERTagger

    ner_tagger = NewsNERTagger(emb)
    doc.tag_ner(ner_tagger)
    doc.ner.print()
# #------
    #     from yargy import Parser
    #     from ipymarkup import show_span_box_markup as show_markup
#
    #     parser = Parser(...)
    #     matches = parser.findall(text)
    #     spans = [_.span for _ in matches]
    #     show_markup(text, spans)
# --

    import json

    from ipymarkup import show_span_ascii_markup as show_markup

    from yargy import(
        Parser,
        rule, or_, and_, not_
        )
    from yargy.predicates import(
        eq, in_,
        type, normalized,
        dictionary,
        gte, lte
        )
    from yargy.pipelines import(
        pipeline,
        morph_pipeline
        )
    from yargy.interpretation import(
        fact,
        attribute
        )
    from yargy.tokenizer import MorphTokenizer, EOL

    Intro = fact(
        'Intro',
        ['gender', 'age', 'birth', 'location',
        attribute('citizenship').repeatable(),
        attribute('permission').repeatable(),
        'relocation', 'travel',
        'position',
        attribute('subspecializations').repeatable(),
        'employment', 'schedule', 'commute',
        'salary'
        ]
)

INT = type('INT')
COMMA = eq(',')
COLON = eq(':')


def show_json(data) :
    print(json.dumps(data, indent = 2, ensure_ascii = False))


    def show_matches(rule, *lines) :
    parser = Parser(rule)
    for line in lines :
matches = parser.findall(line)
spans = [_.span for _ in matches]
show_markup(line, spans)


from razdel import tokenize, sentenize

list(tokenize(text))

# show_markup(text, spans)
# show_json(facts)
sdf = pd.DataFrame.from_records(stext)
sdf.to_csv("output_analiz_safe_guard.csv")
# sdf.to_excel("output_analiz_pd_handle.xls")
