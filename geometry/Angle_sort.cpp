//極角排序
//atan2(y, x) version
// p is reference point
// 180 度開始, 逆時針排序, 剛好在 180 度會排最後
bool cmp(Pt &lhs, Pt rhs) {
    return atan2((lhs - p).y, (lhs - p).x) < atan2((rhs - p).y, (rhs - p).x);
}

//cross product version
// p is reference point
// 270 度開始, 逆時針排序, 剛好在 270 度會排最後
bool cmp(const Pt& lhs, const Pt& rhs) {
    if ((lhs < p) ^ (rhs < p)) return (lhs < p) < (rhs < p);
    return ((lhs - p) ^ (rhs - p)) > 0;
}