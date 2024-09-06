ld Distance_of_Line_and_Point(Line l, Pt p) {
    ld cross_product = abs((p - l.s) ^ l.v);
    ld line_length = sqrtl(l.v * l.v);
    return cross_product / line_length;
}