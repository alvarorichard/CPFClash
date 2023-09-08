const std = @import("std");



pub const generate = struct {
    m_number: []u8 = undefined,
};

pub fn generate() void {
 
const rng = std.rand.DefaultPrng.init(@intCast(u64, std.time.milliTimestamp()));
var buffer: [11]u8 = undefined;
var k: u8 = 0;
var i: u8 = 0;

for ( i < 9; i += 1) |&| {
    buffer[i] = @intToByte(u8, rng.randomIn(0, 9) + 48);
    k += buffer[i] - 48;

}
    k %= 11;
    buffer[9] = @intToByte(u8, k + 48);

    k = 0;
    for (i := 0; i < 10; i += 1) |&| {
        k += buffer[i] - 48;
    }

    k %= 11;
    buffer[10] = @intToByte(u8, k + 48);

    const result = buffer[0..11];
    generate.m_number = std.mem.dupe(result);

    const formatted_cpf = try formatCpf(result);
    if (formatted_cpf != null) {
        @import("std").debug.print("{s}\n", .{@ptrCast([]const u8, formatted_cpf)});
    }
}

pub fn formatCpf(cpf: []u8) !?[]u8 {
    if (cpf.len != 11) {
        return null;
    }

    var formatted: [14]u8 = undefined;
    var j: usize = 0;

    for (i := 0; i < 11; i += 1) |&| {
        if (i == 3 || i == 6) {
            formatted[j] = '.' as u8;
            j += 1;
        } else if (i == 9) {
            formatted[j] = '-' as u8;
            j += 1;
        }

        formatted[j] = cpf[i];
        j += 1;
    }

    return try formatted[0..14];
}

