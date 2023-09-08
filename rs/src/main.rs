use rand::Rng;
use std::env;
use std::fmt;
use std::time::{SystemTime, UNIX_EPOCH};

struct Cpf {
    m_numbs: String,
}

impl Cpf {
    fn new() -> Self {
        let mut rng = rand::thread_rng();
        let mut m_numbs = String::new();

        for _ in 0..9 {
            m_numbs += &(rng.gen_range(0..=9)).to_string();
        }

        let mut cpf = Cpf { m_numbs };
        cpf.generate_first_digit();
        cpf.generate_second_digit();
        cpf
    }

    fn generate_first_digit(&mut self) {
        let mut d1 = 0;
        let mut k = 10;

        for c in self.m_numbs.chars() {
            let digit = c.to_digit(10).unwrap();
            d1 += digit * k;
            k -= 1;
        }

        if d1 % 11 < 2 {
            self.m_numbs += "0";
        } else {
            self.m_numbs += &(11 - (d1 % 11)).to_string();
        }
    }

    fn generate_second_digit(&mut self) {
        let mut d2 = 0;
        let mut k = 10;

        for c in self.m_numbs.chars().skip(1) {
            let digit = c.to_digit(10).unwrap();
            d2 += digit * k;
            k -= 1;
        }

        if d2 % 11 < 2 {
            self.m_numbs += "0";
        } else {
            self.m_numbs += &(11 - (d2 % 11)).to_string();
        }
    }

    fn format_cpf(&mut self) {
        self.m_numbs.insert(self.m_numbs.len() - 8, '.');
        self.m_numbs.insert(self.m_numbs.len() - 5, '.');
        self.m_numbs.insert(self.m_numbs.len() - 2, '-');
    }

    fn check_cpf(&mut self, cpf: &str) -> bool {
        // Limpa o CPF
        let cpf = cpf.chars().filter(|c| c.is_digit(10)).collect::<String>();

        // Verificar se o CPF é somente números
        if !cpf.chars().all(|c| c.is_digit(10)) {
            return false;
        }

        self.m_numbs = cpf.chars().take(9).collect::<String>();
        self.generate_first_digit();
        self.generate_second_digit();
        self.m_numbs == cpf
    }
}

impl fmt::Display for Cpf {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "{}", self.m_numbs)
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();

    let mut rng = rand::thread_rng();
    let seed = SystemTime::now()
        .duration_since(UNIX_EPOCH)
        .unwrap()
        .as_secs() as u64;
    rng = rand::thread_rng();

    let mut c = Cpf::new();
    if args.len() > 1 {
        let arg = &args[1];
        if arg == "--format" {
            c.format_cpf();
            println!("{}", c);
        } else if c.check_cpf(arg) {
            println!("\u{2714} CPF válido!");
        } else {
            eprintln!("\u{2716} CPF ou Parâmetro inválido.");
            std::process::exit(1);
        }
    } else {
        println!("{}", c);
    }
}
