def reverseDLL(head):
    current = head
    _prev = None
    while current:
        _next = current.next
        if _prev is None:
            current.next = _prev
        else:
            current.next = _prev
            _prev.prev = current
        _prev = current
        current = _next
    _prev.prev = None
    head = _prev
    return head
