ld Dis_of_Segment_and_Point(Pt a, Pt b, Pt o) {
    Pt v = b - a;
    if(v * (o - a) <= 0) return norm(o - a);
    if(v * (o - b) >= 0) return norm(o - b);
    ld cross_product = abs((o - a) ^ v);
    ld line_length = sqrtl(v * v);
    return cross_product / line_length;
}