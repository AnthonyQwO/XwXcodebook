// radian of OA and OB (directed angle)
ld Angle_of_two_vector(Pt A, Pt B, Pt O) {
    ld a = (A - O) * (B - O);
    ld b = (A - O) ^ (B - O);
    ld theta = atan2(b, a);
    return theta;
}
