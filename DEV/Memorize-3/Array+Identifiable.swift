//
//  Array+Identifiable.swift
//  Memorize-3
//
//  Created by Revanth_Avs on 12/06/21.
//

import Foundation

extension Array where Element: Identifiable {
    func firstIndex (matching: Element) -> Int? {
        for index in 0..<self.count {
            if self[index].id == matching.id {
                return index
            }
        }
        return nil
    }
}
