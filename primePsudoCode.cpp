Function isPrime(n):
    If n < 2:
        Return false
    End If

    For i = 2 to i*i < n:
        If n % i == 0:
            Return false
        End If
    End For

    Return true
End Function
