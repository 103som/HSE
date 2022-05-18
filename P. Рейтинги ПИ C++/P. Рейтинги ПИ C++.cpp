bool compare(Student& one, Student& two) {
    if (one.rating != two.rating)
        return one.less(two);

    return one < two;
}