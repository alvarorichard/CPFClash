package main

import (
    "fmt"
    "os"
    "strconv"
    //"strings"
    "time"
    "math/rand"
)

type Cpf struct {
    mNumbs string
}

func NewCpf() *Cpf {
    mNumbs := ""
    for i := 0; i < 9; i++ {
        mNumbs += strconv.Itoa(rand.Intn(10))
    }

    cpf := &Cpf{mNumbs: mNumbs}
    cpf.generateFirstDigit()
    cpf.generateSecondDigit()
    return cpf
}

func (cpf *Cpf) generateFirstDigit() {
    d1 := 0
    k := 10

    for _, c := range cpf.mNumbs {
        digit, _ := strconv.Atoi(string(c))
        d1 += digit * k
        k--
    }

    if d1%11 < 2 {
        cpf.mNumbs += "0"
    } else {
        cpf.mNumbs += strconv.Itoa(11 - (d1 % 11))
    }
}

func (cpf *Cpf) generateSecondDigit() {
    d2 := 0
    k := 10

    for _, c := range cpf.mNumbs[1:] {
        digit, _ := strconv.Atoi(string(c))
        d2 += digit * k
        k--
    }

    if d2%11 < 2 {
        cpf.mNumbs += "0"
    } else {
        cpf.mNumbs += strconv.Itoa(11 - (d2 % 11))
    }
}

func (cpf *Cpf) formatCpf() {
    cpf.mNumbs = cpf.mNumbs[:3] + "." + cpf.mNumbs[3:6] + "." + cpf.mNumbs[6:9] + "-" + cpf.mNumbs[9:]
}

func (cpf *Cpf) checkCpf(inputCpf string) bool {
    // Limpa o CPF
    cleanedCpf := ""
    for _, c := range inputCpf {
        if c >= '0' && c <= '9' {
            cleanedCpf += string(c)
        }
    }

    // Verificar se o CPF contém apenas números
    if cleanedCpf != inputCpf {
        return false
    }

    cpf.mNumbs = cleanedCpf[:9]
    cpf.generateFirstDigit()
    cpf.generateSecondDigit()
    return cpf.mNumbs == cleanedCpf
}

func (cpf *Cpf) String() string {
    return cpf.mNumbs
}

func main() {
    args := os.Args

    rand.Seed(time.Now().UnixNano())

    var c *Cpf
    if len(args) > 1 {
        arg := args[1]
        if arg == "--format" {
            c = NewCpf()
            c.formatCpf()
            fmt.Println(c)
        } else if c.checkCpf(arg) {
            fmt.Println("\u2714 CPF válido!")
        } else {
            fmt.Println("\u2716 CPF ou parâmetro inválido.")
            os.Exit(1)
        }
    } else {
        c = NewCpf()
        fmt.Println(c)
    }
}
