
int main() {
    p = L.head;
    q = L.head;
    bool loop = false;
    while (true) {
        if (NULL == p->next || NULL == q->next)
            break;
        p = p->next;
        q = q->next;
        if (p == q) {
            loop = true;
            break;
        }
    }
    return 0;
}

int main() {
    i = 0;
    j = n-1;
    while (i < j) {
        if (1 == a[i]%2)
            i = i+1;
        if (0 == a[j]%2)
            j = j-1;
        if (1 == a[i]%2 && 0 == a[j]%2) {
            swap(a[i],a[j]);
            i = i+1;
            j = j-1;
        }
    }
    return 0;
}